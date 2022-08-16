import java.util.*
import kotlin.collections.ArrayList

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
        var events = TreeMap<Int, Int>();
        for(j in 0..n-1){
            val (a, b) = readInts();
            if(!events.containsKey(a)){
                events.put(a, 0);
            }
            if(!events.containsKey(b + 1)) events[b + 1] = 0;
            events.get(a)?.plus(1)?.let { events.put(a, it) };
            events.get(b + 1)?.minus(1)?.let { events.put(b + 1, it) };
        }
        var curr = 0;
        var which = -1;
        events.forEach(){
            val pos = it.key;
            curr += it.value;
            if(curr == 1){
                which = pos;
            }
        }
        println(which);
    }
}