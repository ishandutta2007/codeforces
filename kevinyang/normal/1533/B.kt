private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles
fun main(args: Array<String>) {
    var t = readInt();
    repeat(t){
    	var n = readInt();
    	var a = readInts();
    	var ans = 0;
    	for(i in 0..n-2){
    		if(a[i+1]%2==a[i]%2)ans = 1;
    	}
    	if(ans==1){
    		println("YES");
    	}
    	else{
    		println("NO");
    	}
    }
}