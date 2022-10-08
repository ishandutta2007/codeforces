import java.io.*;
import java.util.*;

public class Solution {
	public void doMain() throws Exception {
		Scanner sc = new Scanner(System.in);
		PrintWriter pw = new PrintWriter(System.out);
		int N = sc.nextInt();
		String[] pl = new String[N];
		int[] score = new int[N];
		for (int i=0; i<N; i++) {
			pl[i] = sc.next();
			score[i] = sc.nextInt();
		}
		Map<String, Integer> curScore = new HashMap<String, Integer>();
		for (int i=0; i<N; i++) {
			int have = (curScore.containsKey(pl[i]) ? curScore.get(pl[i]) : 0);
			curScore.put(pl[i], have + score[i]);
		}
		int max = 0;
		for (String s : curScore.keySet())
			max = Math.max(max, curScore.get(s));
		Map<String, Integer> curScore1 = new HashMap<String, Integer>();
		for (int i=0; i<N; i++) {
			int have = (curScore1.containsKey(pl[i]) ? curScore1.get(pl[i]) : 0);
			if (have + score[i] >= max && curScore.get(pl[i]) == max) {
				pw.println(pl[i]);
				break;
			}
			curScore1.put(pl[i], have + score[i]);
		}
		pw.flush();
		pw.close();
		sc.close();
	}
	
	public static void main(String[] args) throws Exception {
		(new Solution()).doMain();
	}
}