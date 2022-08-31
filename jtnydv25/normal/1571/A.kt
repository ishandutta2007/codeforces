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
    repeat(readInt()){
        val s = readLn()
        val greater = s.filter { it== '>' }.length
        val smaller = s.filter { it== '<' }.length
        if(smaller > 0 && greater > 0){
            println("?")
        } else if(smaller > 0){
            println("<")
        } else if(greater > 0){
            println(">")
        } else{
            println("=")
        }
    }
}