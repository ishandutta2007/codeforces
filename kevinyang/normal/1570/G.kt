private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles
fun main(args: Array<String>) {
	print("? ");
	for(i in 0..99){
		print(i*128);
		print(" ");
	}
	println();
	var v = readInt();
	print("? ");
	for(i in 1..100){
		print(i);
		print(" ");
	}
	println();
	var v2 = readInt();
	var ans = (v and 127) + (v2 and (127*128));
	print("! ");
	println(ans);
}