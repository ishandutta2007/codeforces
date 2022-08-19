import java.util.*
import kotlin.math.*
import kotlin.system.exitProcess

private fun readLn() = readLine()!! // string line
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of int

val MAXN = 200005
val MAXT = 270005
val INF = 987654321

val gph = Array(MAXN) { mutableListOf<Int>() }
var A = listOf<Int>()
var B = listOf<Int>()
var par = Array(MAXN) { 0 }
var dep = Array(MAXN) { 0 }

fun dfs(x : Int, p : Int) : Pair<Int, Int>{
	var ret = Pair(-INF, x)
	if(A[x] != B[x]) ret = Pair(0, x)
	for(i in gph[x]){
		if(i == p) continue
		par[i] = x
		dep[i] = dep[x] + 1
		var (p, q) = dfs(i, x)
		p++
		if(ret.first < p){
			ret = Pair(p, q)
		}
	}
	return ret
}

var C1 = mutableListOf<Pair<Int, Int>>()
var C2 = mutableListOf<Pair<Int, Int>>()
var dep2 = Array(MAXN) { 0 }

fun collect1(x : Int, p : Int){
	C1.add(Pair(x, B[x]))
	for(i in gph[x]){
		if(i != p && B[x] == A[i]){
			dep2[i] = dep2[x] + 1
			collect1(i, x)
		}
	}
}

fun collect2(x : Int, p : Int){
	C2.add(Pair(x, A[x]))
	for(i in gph[x]){
		if(i != p && A[x] == B[i]){
			dep2[i] = dep2[x] + 1
			collect2(i, x)
		}
	}
}

var ans = INF
var p1 = 0
var p2 = 0

fun solve2(r : Int, v : Int) {
	par[r] = 0
	dfs(r, -1)
	var nv = v
	var len = 2
	while(par[nv] != r){
		if(A[par[nv]] != B[nv]) return
		nv = par[nv]
		len++
	}
	if(A[par[nv]] != B[nv]) return
	C1.clear()
	C2.clear()
	dep2[par[nv]] = 0
	dep2[v] = 0
	collect1(par[nv], nv)
	collect2(v, par[v])
	C1.sortBy { 1L * INF * it.second + dep2[it.first]}
	C2.sortBy { 1L * INF * it.second + dep2[it.first]}
	var ptr = 0
	for(i in C1){
		while(ptr < C2.size && C2[ptr].second < i.second) ptr++
		if(ptr < C2.size && C2[ptr].second == i.second){
			var length = len + dep2[C2[ptr].first] + dep2[i.first]
			if(ans > length){
				ans = length
				p2 = i.first
				p1 = C2[ptr].first
			}
		}
	}
}

fun solve(){
	ans = INF
	val n = readInts()[0]
	for(i in 0 until n+1){
		gph[i].clear()
	}
	A = readInts()
	B = readInts()
	for (i in 1 until n){
		val (x, y) = readInts()
		gph[x-1].add(y-1)
		gph[y-1].add(x-1)
	}
	var cnt = 0
	for(i in 0 until n){
		if(A[i] != B[i]) cnt++
	}
	if(cnt == 0){
		println("Yes\n0")
		return
	}
	if(cnt == 1){
		println("No")
		return
	}
	val s = dfs(0, -1).second
	val e = dfs(s, -1).second
	var tmp = e
	while(tmp != s){
		if(A[tmp] != B[tmp]) cnt--
		tmp = par[tmp]
	}
	if(A[s] != B[s]) cnt--
	if(cnt != 0){
		println("No")
		return
	}
	solve2(s, e)
	solve2(e, s)
	if(ans > n + 10){
		println("No")
		return
	}
	dep[p2] = 0
	dfs(p2, -1)
	println("Yes")
	println((dep[p1] + 1))
	while(p1 != p2){
		print((p1 + 1).toString() + " ")
		p1 = par[p1]
	}
	println(p1 + 1)
}

fun main() {
	var t = readInts()[0]
	for(i in 0 until t){
		solve()
	}
}