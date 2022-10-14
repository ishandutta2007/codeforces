//package a2oj;
import java.util.*;
public class GoodSubstrings {
	static class Node{
		Node[]children=new Node[26];
	}
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		char[]s=sc.nextLine().toCharArray();
		char[]good=sc.nextLine().toCharArray();
		int k=sc.nextInt();
		int[]dp=new int[s.length];
		for(int i=0;i<s.length;i++){
			if(i>0)
				dp[i]=dp[i-1];
			if(good[s[i]-'a']=='0')
				dp[i]++;
		}
		Node root=new Node();
		int ans=0;
		for(int i=0;i<s.length;i++){
			Node n=root;
			for(int j=i;j<s.length;j++)
				if(dp[j]-(i==0?0:dp[i-1])<=k){
					if(n.children[s[j]-'a']==null){
						n.children[s[j]-'a']=new Node();
						ans++;
					}
					n=n.children[s[j]-'a'];
				}else
					break;
		}
		System.out.println(ans);
		sc.close();
	}
}