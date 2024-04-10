import java.util.*
import kotlin.math.*

fun readLn() = readLine()!!
fun readInt() = readLn().toInt()
fun readStrings() = readLn().split(" ")
fun readInts() = readStrings().map { it.toInt() }
fun readLong() = readLn().toLong()
fun readLongs() = readStrings().map { it.toLong() }

fun solve(){
    var n = readInt()
    var a = readInts().toIntArray()
    for(i in 0 until n-1){
        if((a[i] + a[i+1])%2 == 0){
            println("YES")
            return
        }
    }
    println("NO")
}

fun main() {
    var t = readInt()
    while(t > 0){
        t--
        solve()
    }
}