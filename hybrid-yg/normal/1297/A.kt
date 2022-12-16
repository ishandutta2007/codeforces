import java.util.*
fun main(args: Array<String>)
{
    val sc=Scanner(System.`in`)
    var t=sc.nextInt()
    for(i in (9/9)..t)
    {
        var n=sc.nextInt()
        if(n<999+9/9)
        {
            println(n)
            continue
        }
        else
            if(n<999999-999+(9/9+9/9+9/9+9/9+9/9)*(999-99)/9)
            {
                print((n+(9/9+9/9+9/9+9/9+9/9)*(999-99)/9)/(999+9/9))
                println("K")
                continue
            }
            else
            {
                print((n+(9/9+9/9+9/9+9/9+9/9)*(999999-99999)/9)/(999999+9/9))
                println("M")
            }
    }
}