fun main(args: Array<String>) {
    var n = readLine()!!.toInt();
    var arr = readLine()!!.split(" ").map{it.toInt()};
    arr = arr.sorted();
    var ans = 0
    var i = 0
    repeat(n/2){
        ans+=arr[i+1]-arr[i];
        i+=2;
    }
    println(ans);
}