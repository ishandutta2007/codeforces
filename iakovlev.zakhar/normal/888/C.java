import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class C {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String s = in.readLine();
		int ans = s.length();
		for (char c = 'a'; c <= 'z'; c++) {
			int last = -1;
			int th = 0;
			for (int i = 0; i < s.length(); i++) {
				if (s.charAt(i) == c) {
					th = Math.max(th, i - last);
					last = i;
				}
			}
			th = Math.max(th, s.length() - last);
			ans = Math.min(th, ans);
		}
		System.out.println(ans);
		in.close();
	}

}