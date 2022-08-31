import java.lang.AssertionError
 
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
    val A = Array(n) {Array(n) {0} }
    val B = Array(n){0}
    val C = Array(n){0}
    val f = Array(m){0}
    val l = Array(m){0}
    for(i in 0..m-1){
        val (p, q) = readInts()
        f[i] = p - 1
        l[i] = q - 1
        A[f[i]][l[i]]+=1
        B[f[i]]+=1
        C[l[i]]+=1
    }
    var rank = 1
    for(i in 0..n-1){
        for(j in 0..n-1) if(i != j){
            val both = A[i][j]
            val one = B[i] + C[j] - 2 * both
            var my = 2
            if(i == f[0]) my-=1
            if(j == l[0]) my-=1
            if(my==1) rank = maxOf(rank, both + 1)
            if(my==2) rank = maxOf(rank, both + one + 1)
        }
    }
    println(rank)
}