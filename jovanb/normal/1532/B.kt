private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map {it.toLong() } // list of longs

fun solve(){
    var (a, b, k) = readLongs()
    var gde = (k/2)*(a-b)
    if(k%2 > 0L) {
        gde += a
    }
    println(gde)
}

fun main() {
    var t = readInt()
    while(t > 0){
        t--
        solve()
    }
}