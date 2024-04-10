fun main() {
    var n = readInt();
    var c = readInts();
    var b = IntArray(n);
    var a = Array(n){ IntArray(2) };
    for(i in 0..n - 1) {
        a[i] = intArrayOf(c[i], i);
    }
    a.sortBy{-it[0]};
    var res = 0;
    for(i in 0..n - 1) {
        b[i] = a[i][1];
        res += i * a[i][0] + 1;
    }
    println(res);
    for(i in 0..n - 1) {
        print(b[i] + 1);
        print(" ");
    }
}

private fun readInt() = readLine()!!.toInt();
private fun readInts() = readLine()!!.split(" ").map{x -> x.toInt()};