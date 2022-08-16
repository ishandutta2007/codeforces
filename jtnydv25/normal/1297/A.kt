import java.lang.Long.max
import java.lang.Long.min

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun main(){
    val t = readInt();
    for(i in 0..t-1){
        val n = readInt();
        if(n< 1000){
            println(n);
        }
        else if(n >= 999500){
            var ret = n / 1000000;
            val rem = n % 1000000;
            if(rem >= 500000) ret++;
            print(ret); println("M");
        } else{
            var ret = n / 1000;
            val rem = n % 1000;
            if(rem >= 500) ret++;
            print(ret); println("K");
        }
    }
}