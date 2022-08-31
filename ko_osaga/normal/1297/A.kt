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
	var x = readInts()[0]
	if (x <= 999){
		println(x)
		return
	}
	if ((x + 500) / 1000 <= 999){
		x = (x + 500) / 1000
		println(x.toString() + "K")
		return
	}
	x = (x + 500000) / 1000000;
	println(x.toString() + "M")
}

fun main() {
	var t = readInts()[0]
	for(i in 0 until t){
		solve()
	}
}