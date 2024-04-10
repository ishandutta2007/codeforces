import java.util.*;

public class Program {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        ArrayList<String> curDir = new ArrayList<String>();
        while (N-- != 0) {
            String command = in.next();
            if (command.equals("pwd")) {
                for (String c: curDir)
                    System.out.print("/" + c);
                System.out.println("/");
            } else {
                String[] l = in.next().split("/");
                for (String c: l) {
                    if (c.equals(".."))
                        curDir.remove(curDir.size() - 1);
                    else if (c.equals(""))
                        curDir.clear();
                    else
                        curDir.add(c);
                }
            }
        }
        System.out.flush();
    }

}