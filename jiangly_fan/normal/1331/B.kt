fun main(){
    var a = readLine()!!.toInt()
    while(a > 1){
        for(i in 2..a) if(a % i == 0){
            print(i)
            a /= i
        }
    }
}