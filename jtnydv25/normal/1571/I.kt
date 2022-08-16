import java.lang.AssertionError
import java.util.*
import java.util.Collections.max
import java.util.Collections.min
import kotlin.collections.ArrayList

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles
 
private fun myAssert(x: Boolean) {
    if (!x) {
        throw AssertionError()
    }
}

fun main() {
    val tt = readInt()
    for(qq in 0..tt-1){
        val n = readInt()
        val L = readInts().toMutableList()
        val R = readInts().toMutableList()
        val L0 = max(L)
        val R0 = min(R)
        if(R0 >= L0 + n - 1){
            println(L0)
            println((1..n).joinToString(" "))
            continue
        }
        val X = L.withIndex().sortedBy { -it.value }
        val Y = R.withIndex().sortedBy { it.value }
        var mn = 0
        var mx = 2000000000

        for(i in 0..n-1){
            mx = minOf(mx, Y[i].value - i)
        }
        for(i in 0..n-1){
            mn = maxOf(mn, X[i].value + i - n + 1)
        }
        if(mn > mx){
            println(-1)
            continue
        }
        val x = mn

        val p = Array(n){-1}
        val additions = Array(n){ArrayList<Int>()}
        for(i in 0..n-1){
            L[i] = maxOf(L[i] - x, 0)
            R[i] -= x
            additions[L[i]].add(i)
        }
        val Rs = PriorityQueue<Long>()
        var error = false
        for(i in 0..n-1){
            for(j in additions[i]){
                Rs.add(R[j].toLong() * 1000000 + j)
            }
            if(Rs.isEmpty()){
                error=true
                break
            }
            var k = Rs.poll()
            p[i] = (k % 1000000).toInt()

            if((k / 1000000) < i){
                error = true
                break
            }
        }
        if(error){
            println(-1)
            assert(false)
            continue
        }
        println(x)
        println(p.joinToString(" "){"${it + 1}"})
    }
}