import java.util.ArrayList


fun main()
{

    /*var n=readLine()!!.split((' ')).map(String::toLong)
    var b=n[0];var k=n[1]
    var cnt:Long=0;var ans:Long=0
    class pair(x:Long,y:Long){}
    val mp=ArrayList<Pair<Long,Long> >()
    for(i in 1..b)
    {
        var array=readLine()!!.split(' ').map(String::toLong)
        cnt+=array[0]
        ans+=array[0]*array[2]
        mp.add(array[2]to array[1]-array[0])
    }

    mp.sortBy { it.first }
    var i=0
    while(cnt<k&&i<b)
    {
        if(cnt+mp[i].second<k){cnt+=mp[i].second;ans+=mp[i].first*mp[i].second}
        else if(cnt+mp[i].second>=k){ans+=mp[i].first*(k-cnt);cnt+=k-cnt}
        i++;
        //print(""+cnt+"\n")
    }
if(cnt!=k)print(-1)
    else print(ans)
*/
    var n=readLine()!!.split((' ')).map(String::toLong)
    var i=0
    while(i<n[0])
    {
        var x=readLine()!!.split((' ')).map(String::toLong)
        var xx=x[0]
        var ten=1;
        var zero:Long=0
        var ar=ArrayList<Long>()
        while(xx>0)
        {
            if(xx%10!=zero)
                ar.add(ten*(xx%10))
            ten*=10
            xx/=10
        }
        print(""+ar.size+"\n")
        for(i in 0..ar.size-1)print(""+ar[i]+" ");print("\n")
        i++
    }
}