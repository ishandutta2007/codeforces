private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles
fun main(args: Array<String>) {
	var a = readInt();
	var b = readInt();
	var c = readInt();
	var d = readInt();
	var k = readInt();
	var mx = a*(c-1) + b*(d-1);
	mx = k-mx;
	if(mx<0)mx = 0;
	print(mx);
	print(" ");
	var cnt = 0;
	if(c<d){
		while(k>=c){
			k-=c;
			cnt++;
			if(cnt==a)break;
		}
		while(k>=d){
			k-=d;
			cnt++;
			if(cnt==a+b)break;
		}
	}
	else{
		while(k>=d){
			k-=d;
			cnt++;
			if(cnt==b)break;
		}
		while(k>=c){
			k-=c;
			cnt++;
			if(cnt==a+b)break;
		}
	}
	println(cnt);
}