//package cf568d2;
import java.util.*;
public class A {
    public static void main(String[]args){
        Scanner sc=new Scanner(System.in);
        long[]a=new long[]{sc.nextLong(),sc.nextLong(),sc.nextLong()};
        Arrays.sort(a);
        long d=sc.nextLong();
        System.out.println(Math.max(0,d-Math.abs(a[0]-a[1]))+Math.max(0,d-Math.abs(a[1]-a[2])));
    }
}