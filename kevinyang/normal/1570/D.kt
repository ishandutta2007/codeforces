private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles
fun main(args: Array<String>) {
	var n = readInt();
	var cnt = 0;
	val set = mutableSetOf<Int>()
	set.add(n);
	repeat(1000){
		n++;
		cnt++;
		while(n%10==0){
			n/=10;
		}
		set.add(n);
	}
	println(set.count());
}