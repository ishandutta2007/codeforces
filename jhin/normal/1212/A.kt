fun main()
{
    var(a,b)=readLine()!!.split(' ').map(String::toInt)
    while(b>0)
    {
        if(a%10!=0)a--
        else a/=10
        b--
    }
    print(a)
}