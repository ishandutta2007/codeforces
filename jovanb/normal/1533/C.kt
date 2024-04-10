import java.util.*
import kotlin.math.*

fun readLn() = readLine()!!
fun readInt() = readLn().toInt()
fun readStrings() = readLn().split(" ")
fun readInts() = readStrings().map { it.toInt() }
fun readLong() = readLn().toLong()
fun readLongs() = readStrings().map { it.toLong() }

fun solve(){
    var (n, k) = readInts()
    var a = arrayListOf<Int>()
    var eaten = arrayListOf<Int>()
    for(i in 0 until n) eaten.add(0)
    var s = readLn()
    var likes = 0
    for(i in 0 until n){
        if(s[i] == '0') a.add(0);
        else{
            a.add(1)
            likes++
        }
    }
    var tr = 0
    var cnt = 0
    while(likes > 0){
        cnt++
        eaten[tr] = 1
        if(a[tr] == 1) likes--
        if(likes == 0) break
        var turns = k
        while(turns > 0){
            if(eaten[tr] == 1) tr++
            else{
                turns--
                if(turns > 0) tr++
            }
            if(tr >= n) tr -= n
        }
    }
    println(cnt)
}

fun main() {
    var t = readInt()
    while(t > 0){
        t--
        solve()
    }
}
/*
1
5 1
10011
 */