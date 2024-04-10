import java.util.*;

public class Solution {

	static class TCall implements Comparable<TCall> {
		public TCall(int startTime, int duration) {
			StartTime = startTime;
			Duration = duration;
		}
		public int StartTime;
		public int Duration;
		
		@Override
		public int compareTo(TCall o) {
			if (StartTime < o.StartTime)
				return -1;
			else if (StartTime == o.StartTime)
				return 0;
			else
				return 1;
		}
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int k = in.nextInt();
		TCall[] calls = new TCall[n];
		for (int i = 0; i < n; i++) {
			int s = in.nextInt();
			int d = in.nextInt();
			calls[i] = new TCall(s, d);
		}
		Arrays.sort(calls);
		int result = 0;
		int[] curFinish = new int[k+1];
		Arrays.fill(curFinish, 1);
		for (TCall call: calls) {
			result = Math.max(result, call.StartTime - curFinish[k]);
			for (int j = k; j >= 0; j--) {
				curFinish[j] = Math.max(curFinish[j], call.StartTime) + call.Duration;
				if (j != 0)
					curFinish[j] = Math.min(curFinish[j], curFinish[j-1]);
			}
		}
		result = Math.max(result, 86401 - curFinish[k]);
		System.out.println(result);
	}

}