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
	val idx = Array(n) { it + 1 }
	idx.sortBy { a[it - 1] }

	for(i in 1 until n-1){
		if(a[idx[0]-1] < a[idx[i]-1] && a[idx[i]-1] < a[idx[n-1]-1]){
			println(idx[0].toString() + " " + idx[i].toString() + " " + idx[n-1].toString())
			exitProcess(0)
		}
	}
	println("-1 -1 -1")
}