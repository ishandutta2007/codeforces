private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun main(){
    val n = readInt();
    val str = readLn();
    var num = 0;
    var ans = 0;
    for(i in 0..n-1){
        if(str[i] == 'x'){
            num++;
            if(num == 3){
                ans++; num--;
            }
        } else{
            num = 0;
        }
    }
    println(ans);
}