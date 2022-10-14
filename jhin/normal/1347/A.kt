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
        print(""+(x[0]+x[1])+"\n")
        i++
    }
}