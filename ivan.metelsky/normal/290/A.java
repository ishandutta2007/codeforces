import java.io.InputStreamReader;
import java.util.Scanner;

public class ProblemA {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new InputStreamReader(System.in));
        int a = sc.nextInt();
        System.out.println(
                new String[] {
                        "Washington", "Adams", "Jefferson", "Madison", "Monroe",
                        "Adams", "Jackson", "Van Buren", "Harrison", "Tyler",
                        "Polk", "Taylor", "Fillmore", "Pierce", "Buchanan",
                        "Lincoln", "Johnson", "Grant", "Hayes", "Garfield",
                        "Arthur", "Cleveland", "Harrison", "Cleveland", "McKinley",
                        "Roosevelt", "Taft", "Wilson", "Harding", "Coolidge",
                        "Hoover", "Roosevelt", "Truman", "Eisenhower", "Kennedy",
                        "Johnson", "Nixon", "Ford", "Carter", "Reagan"
                }[a - 1]
        );
        sc.close();
    }
}