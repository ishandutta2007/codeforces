import java.util.*
import kotlin.math.*

fun readLn() = readLine()!!
fun readInt() = readLn().toInt()
fun readStrings() = readLn().split(" ")
fun readInts() = readStrings().map { it.toInt() }
fun readLong() = readLn().toLong()
fun readLongs() = readStrings().map { it.toLong() }

fun main() {
    var a = arrayListOf<Pair<Int, Int>>()
    val n = readInt()
    val nz = readInts().toIntArray()
    var sum = 0L
    for(i in 0 until n){
        //val par = Pair nz[i], i>
        a.add(Pair(nz[i], i))
        sum += nz[i]
    }
    a.sortBy { it.first }
    var sol = arrayListOf<Int>()
    for(i in 0 until n-1){
        sum -= a[i].first;
        if(2L*a[n-1].first == sum) sol.add(a[i].second);
        sum += a[i].first;
    }
    sum -= a[n-1].first;
    if(2L*a[n-2].first == sum) sol.add(a[n-1].second)
    val k = sol.size
    println(k)
    for(i in 0 until k){
        print(sol[i] + 1)
        print(" ")
    }
}