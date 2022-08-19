import java.util.*
import kotlin.math.*
import kotlin.system.exitProcess

private fun readLn() = readLine()!! // string line
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of int

val MAXN = 100005
val MAXT = 270005
val INF = 987654321

fun solve(l : MutableList<Int>, a : Int, b : Int): Int{
	var accm = l.sum()
	var dp = Array(accm + 1){ if (it == 0) 0 else -INF }
	for(i in l){
		var nxt = Array(dp.size){ -INF }
		for(j in 0 until dp.size){
			if(j * a >= dp.size) break
			nxt[j] = max(nxt[j], dp[j * a])
		}
		dp.fill(-INF)
		for(j in 0 until dp.size){
			if(j * b > i) break
			dp[i - j * b] = nxt[j] + j
		}
		for(j in dp.size - 2 downTo 0){
			dp[j] = max(dp[j], dp[j+1])
		}
	}
	return dp.max()!!
}

fun main() {
	var (n, a, b, k) = readInts()
	var c = readInts()
	var cnt = Array(1000005) { 0 }
	for(i in c){
		cnt[i]++
	}
	var ret = 0
	for(i in 1..1000000){
		if(cnt[i] == 0) continue
		var j = i
		var l = mutableListOf<Int>()
		while(j <= 1000000){
			l.add(cnt[j])
			cnt[j] = 0
			j *= k
		}
		ret += solve(l, a, b)
	}
	println(ret)
}