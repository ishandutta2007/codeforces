import java.util.*
import kotlin.math.*
 
fun readLn() = readLine()!!
fun readInt() = readLn().toInt()
fun readStrings() = readLn().split(" ")
fun readInts() = readStrings().map { it.toInt() }
fun readLong() = readLn().toLong()
fun readLongs() = readStrings().map { it.toLong() }
 
fun main(){
    var t = readInt()
    while(t > 0){
        t--
        var (a, b) = readInts()
        println(a + b)
    }
}