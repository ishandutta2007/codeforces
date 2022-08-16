import java.lang.AssertionError
import java.util.*

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
    val (n, m) = readInts()
    var L = m
    val A = arrayListOf<Int>()
    var sum = 0
    val k = Array(n){0}
    val t = Array(n){0}
    val x = Array(n){0}
    val type = Array(n){0}
    var S = 0
    for(i in 0..n-1){
        val (p, q) = readInts()
        k[i] = p
        t[i] = q
        if(q==1){
            L -= p
            x[i] = L + 1
        }
        else{
            A.add(i)
            S += p
        }
        sum += p
    }
    if(sum > m){
        println(-1)
        return
    }
    // max with sum <= L/2
    val dp = Array(A.size + 1){Array(L + 1){false} }
    dp[0][0] = true
    for(i in 0..A.size-1){
        val l = k[A[i]]
        for(j in 0..L){
            dp[i+1][j] = dp[i][j]
            if(j >= l && dp[i][j - l]) dp[i + 1][j] = true
        }
    }
    var mx = 0
    for(i in 0..L/2) if(dp[A.size][i]) mx = i
    if(S - mx > (L + 1) / 2){
        println(-1)
    } else{
        for(i in A.size-1 downTo 0){
            if(mx >= k[A[i]] && dp[i][mx - k[A[i]]]){
                type[i] = 1
                mx -= k[A[i]]
            }
        }

        var p = 1; var q = 2
        for(i in 0..n-1){
            if(t[i]==1) continue
            if(type[i] == 1){
                x[i] = q
                q += 2 * k[i]
            } else{
                x[i] = p
                p += 2 * k[i]
            }
        }
        println(x.joinToString(" "))
    }
}