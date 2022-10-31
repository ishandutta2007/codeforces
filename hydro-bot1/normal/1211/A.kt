// Hydro submission #62ef21c674879b352565db8a@1659838919218
import java.util.Scanner
fun main()
{
    var a:Int=0;var b:Int=0
    var pa:Int=0;var pb:Int=0
    val cin=Scanner(System.`in`)
    val n:Int=cin.nextInt();val i:Int
    for(i in 1..n)
    {
        val r:Int=cin.nextInt()
        if(a==0)
        {
            a=r
            pa=i
        }
        else if(b==0)
        {
            if(r!=a)
            {
                b=r
                pb=i
            }
        }
        else if(r!=a&&r!=b)
        {
            if(a<b&&a<r)
            {
                print("$pa ")
                if(b<r) println("$pb $i")
                else println("$i $pb")
            }
            else if(b<a&&b<r)
            {
                print("$pb ")
                if(a<r) println("$pa $i")
                else println("$i $pa")
            }
            else
            {
                print("$i ")
                if(a<b) println("$pa $pb")
                else println("$pb $pa")
            }
            return
        }
    }
    println("-1 -1 -1")
    return
}