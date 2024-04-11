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
	val n = readInts()[0]
	val a = readInts().toIntArray()
	var ret = 0L
	for(i in 0 until n){
		if(a[i] == 0) continue
		ret = max(ret, (a[i] - 1L) * n + i + 1)
	}
	println(ret)
}