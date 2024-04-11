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
	var (n, k) = readInts()
	val arr = Array(n){ Pair(0, 0)}
	var dap = 0L
	for(i in 0 until n){
		val (x, y, z) = readInts()
		k -= x
		if(k < 0) break
		dap += 1L * x * z
		arr[i] = Pair(y - x, z)
	}
	if(k < 0){
		println("-1")
		exitProcess(0)
	}
	arr.sortBy { it.second }
	for(i in 0 until n){
		val dx = min(k, arr[i].first)
		k -= dx
		dap += 1L * dx * arr[i].second
	}
	if(k > 0){
		println("-1");
		exitProcess(0)
	}
	println(dap)
}