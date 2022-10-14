//package helvetic2019mirror;

import java.util.ArrayList;
import java.util.Scanner;

public class A2 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		sc.nextLine();
		char[] s = sc.nextLine().toCharArray();
		ArrayList<Integer> divisors = new ArrayList<Integer>();
		if(n > 1)
			divisors.add(1);
		for(int i = 2; i * i <= n; i++)
			if(n % i == 0) {
				divisors.add(i);
				if(i != n / i)
					divisors.add(n / i);
			}
		boolean[][]arr=new boolean[divisors.size()][n];
		for(int i = 0; i < n; i++)
			if(s[i] == '1')
				for(int j = 0; j < divisors.size(); j++)
					arr[j][i % divisors.get(j)] = !arr[j][i % divisors.get(j)];
		boolean[] bad = new boolean[n];
		for(int i = 0; i < divisors.size(); i++)
			for(int j = 0; j < divisors.get(i); j++)
				if(arr[i][j])
					bad[divisors.get(i)] = true;
		boolean zero = true;
		for(char c:s)
			if(c == '1')
				zero = false;
		int ct = zero ? 1 : 0;
		for(int i = 1; i < n; i++)
			if(!bad[gcd(i,n)])
				ct++;
		System.out.println(ct);
	}
	static int gcd(int a,int b){
		return b == 0 ? a : gcd(b, a%b);
	}
}