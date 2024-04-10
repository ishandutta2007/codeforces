import java.io.*;
import java.util.*;
import java.math.*;
import java.lang.*;
import java.util.Arrays;

public class Main {
	static BigInteger[] a=new BigInteger[10005];
	static BigInteger[] b=new BigInteger[10005];
	static int n;
	static void debug(Object... os) {
		System.err.println(Arrays.deepToString(os));
	}
	static BigInteger solve(int c){
		BigInteger ONE=BigInteger.ONE,TWO=ONE.add(ONE),C=new BigInteger(Integer.toString(c));
		BigInteger lb=BigInteger.ZERO,ub=BigInteger.TEN.pow(30);
		while(ONE.compareTo(ub.subtract(lb))==-1){
			BigInteger md=lb.add(ub).divide(TWO);
			BigInteger days=BigInteger.ZERO;
			for(int i=0;i<n;++i){
				days=days.add(md.multiply(a[i]).divide(b[i]).add(ONE));
			}
			if(days.compareTo(C)<=0) lb=md;
			else ub=md;
		}
		return ub;
	}

	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		n=sc.nextInt();
		int c=sc.nextInt();
		
		boolean allzero=true;
		for(int i=0;i<n;++i){
			a[i]=sc.nextBigInteger();
			if(a[i].compareTo(BigInteger.ZERO)!=0) allzero=false;
			b[i]=sc.nextBigInteger();
		}
		if(allzero){
			if(n==c) System.out.println("-1");
			else System.out.println("0");
		}else{
			BigInteger ans=solve(c).subtract(solve(c-1));
			System.out.println(ans.toString());
		}
	}
}