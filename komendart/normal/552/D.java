import java.util.Scanner;


public class D {
	
	public static void main(String[] args) {
		
		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		int[] X = new int[n];
		int[] Y = new int[n];
		for(int i = 0; i < n; i++) {
			X[i] = scanner.nextInt();
			Y[i] = scanner.nextInt();
			
		}
		
		int ans = 0;
		for(int i = 0; i < n; i++) {
			for(int j = i + 1; j < n; j++) {
                                int a = X[j] - X[i];
                                int b = Y[j] - Y[i];
                                int v = X[j] * Y[i] - Y[j] * X[i];
				for(int k = j + 1; k < n; k++) {
					if(a * Y[k] - b * X[k] != v) {
						ans++;
					}
				}
			}
		}
		System.out.println(ans);
       }
}