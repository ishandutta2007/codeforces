import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {
    static int min(int a,int b)
    {
        if(a<b)
            return a;
        else
            return b;
    }
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);        
        int n=sc.nextInt();
        int start=sc.nextInt()-1;
        int x=sc.nextInt();
        int used[]=new int[n];
        System.out.println("?"+" "+(start+1));
        System.out.flush();
        ArrayList<Pair> list=new ArrayList<>();
        Random r=new Random();
        list.add(new Pair(sc.nextInt(),sc.nextInt()-1));
        used[start]=1;
        if(list.get(0).next!=-2)
            used[list.get(0).next]=1;
        for(int i=0;i<min(999,(n+1)/2-1);i++)
        {
            int var=r.nextInt(n);
            while(used[var]==1)
                var=r.nextInt(n);
            System.out.println("?"+" "+(var+1));
            System.out.flush();
            list.add(new Pair(sc.nextInt(),sc.nextInt()-1));
            used[var]=1;
            if(list.get(list.size()-1).next!=-2)
                used[list.get(list.size()-1).next]=1;
        }
        int next=list.get(0).next,value=list.get(0).value;
        for(int i=0;i<list.size();i++)
        {
            if(list.get(i).value>value&&list.get(i).value<=x)
            {
                next=list.get(i).next;
                value=list.get(i).value;
            }
        }
        int ans=value;
        while(next!=-2&&ans<x)
        {
            System.out.println("?"+" "+(next+1));
            System.out.flush();
            ans=sc.nextInt();
            next=sc.nextInt()-1;
        }
        if(ans<x)
            System.out.print("! -1");
        else
            System.out.print("! "+ans);
    }
}
class Pair
{
    int value;
    int next;
    Pair(int value,int next)
    {
        this.value=value;
        this.next=next;
    }
}