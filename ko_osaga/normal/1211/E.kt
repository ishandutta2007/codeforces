import java.util.*
import kotlin.math.*
import kotlin.system.exitProcess

private fun readLn() = readLine()!! // string line
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of int

val MAXN = 100005
val MAXT = 270005
val INF = 987654321


fun main() {
	var n = readInts()[0]
	var a = readInts()
	var str = Array(n) { -1 }
	var cnt = Array(200005) { 0 }
	for (i in 0 until n){
		cnt[a[i]]++
	}
	var p = 0
	while(cnt[p + 1] == 2) p++
	fun trial(x : Int) : Boolean{
		str.fill(-1)
		var cnt = Array(x + 1) { 2 }
		var l = mutableListOf<Int>()
		var r = mutableListOf<Int>()
		for(i in 0 until n){
			if(a[i] <= x){
				cnt[a[i]]--
				str[i] = cnt[a[i]]
				if(str[i] == 1) l.add(a[i])
				else r.add(a[i])
			}
		}
		for(i in 0 until x){
			if(l[i] != r[i]) return false
		}
		return true
	}
	var s = 0
	var e = p
	while(s != e){
		var m = (s+e+1)/2
		if(trial(m)) s = m
		else e = m-1
	}
	trial(s)
	for(i in 0 until n){
		if(str[i] == 0) print("R")
		else if(str[i] == 1) print("G")
		else print("B")
	}
}