import java.util.*
import kotlin.collections.HashMap
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
    var b = readInts().toIntArray()
    a.sort()
    b.sort()
    var pre = arrayListOf<Int>()
    var suf = arrayListOf<Int>()
    for(i in 0 until n){
        pre.add(b[i] - a[i])
        if(i > 0) pre[i] = max(pre[i], pre[i-1])
    }
    for(i in 0 until n) suf.add(0)
    for(i in n-1 downTo 0){
        suf[i] = b[i+1] - a[i]
        if(i < n-1) suf[i] = max(suf[i], suf[i+1])
    }
    var q = readInt()
    var y = readInts().toIntArray()
    for(qr in 0 until q){
        var x = y[qr]
        var l = 1
        var r = n
        var rez = 0
        while(l <= r){
            var mid = (l+r)/2
            if(a[mid-1] < x){
                rez = mid
                l = mid+1
            }
            else r = mid-1
        }
        var res = b[rez] - x
        if(rez > 0) res = max(res, pre[rez-1])
        if(rez < n) res = max(res, suf[rez])
        print(res)
        print(" ")
    }
}

fun main() {
    var t = 1
    while(t > 0){
        t--
        solve()
    }
}

/*
5
10 3 4 6 1
9 4 2 5 9 8
1
8
 */