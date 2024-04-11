import java.util.*
import kotlin.math.*
import kotlin.system.exitProcess

private fun readLn() = readLine()!! // string line
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of int

val MAXN = 100005
val MAXT = 270005
val INF = 987654321

fun f(c : Char) : Int{
	return when(c){
		'k' -> 0
		'o' -> 1
		't' -> 2
		'l' -> 3
		'i' -> 4
		else -> 5
	}
}

var In = Array(6) { mutableListOf<Pair<Int, Int>>() }
var sz = Array(6) { 0 }
var ans = mutableListOf<Int>()

fun dfs(x : Int) {
	while(sz[x] > 0){
		sz[x]--
		var pos = sz[x]
		dfs(In[x][pos].second)
		ans.add(In[x][pos].first)
	}
}

fun main() {
	var n = readInts()[0]
	var str = mutableListOf<String>()
	for (i in 0 until n) {
		str.add(readLn())
		var x = f(str[i][0])
		var y = f(str[i][str[i].length - 1]) + 1
		if (y == 6) y = 0
			In[x].add(Pair(i, y))
			sz[x]++
	}
	dfs(0)
	ans.reverse()
	for(i in ans){
		print((i + 1).toString() + " ")
	}
}