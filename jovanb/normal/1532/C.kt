private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun solve(){
    var (n, k) = readInts()
    var s = ""
    var tr = 0;
    while(n > 0){
        n--;
        s += ('a'.plus(tr))
        tr = (tr+1)%k
    }
    println(s)
}

fun main() {
    var t = readInt()
    while(t > 0){
        t--
        solve()
    }
}