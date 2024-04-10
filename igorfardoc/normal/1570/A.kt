fun main() {
    for(i in 1..readInt()) {
        var a = readInts();
        println(a[0] + a[1]);
    }
}

private fun readInt() = readLine()!!.toInt();
private fun readInts() = readLine()!!.split(" ").map{x -> x.toInt()};