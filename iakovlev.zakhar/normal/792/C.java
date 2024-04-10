import java.io.*;
import java.math.*;
import java.util.*;


public class Main {
    
    public BufferedReader input;
    public PrintWriter output;
    public StringTokenizer stoken = new StringTokenizer("");
    
    public static void main(String[] args) throws IOException {
        new Main();
    }
    
    Main() throws IOException{
        input = new BufferedReader(
                  new InputStreamReader(System.in)
        );
        output = new PrintWriter(System.out);
        String s = nextString();
        int n = s.length();
        int sum = 0;
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = s.charAt(i) - '0';
            sum += a[i];
        }
        if (sum % 3 == 0) {
            output.print(s);
        } else if (sum % 3 == 1) {
            if (n == 1) {
                output.print(-1);   
            } else if (n == 2 && a[0] % 3 == 2) {
                output.print(-1);
            } else {
                int len = -1;
                for (int i = n - 1; i >= 0; i--) {
                    if (a[i] % 3 == 1) {
                        if (i != 0) {
                            for (int j = 0; j < n; j++) {
                                if (j == i) {
                                    continue;
                                }
                                output.print(a[j]);
                            }
                            output.close();
                            return;
                        } else {
                            len = 1;
                            for (int j = 1; j < n - 1; j++) {
                                if (a[j] == 0) {
                                    len++;
                                } else {
                                    break;
                                }
                            }
                            if (len == 2) {
                                output.print(s.substring(2));
                                output.close();
                                return;
                            }
                            if (len == 1) {
                                output.print(s.substring(1));
                                output.close();
                                return;
                            }
                        }
                    }
                }
                int x = -1;
                int y = -1;
                for (int i = n - 1; i >= 0; i--) {
                    if (a[i] % 3 == 2) {
                        if (x == -1) {
                            x = i;
                        } else {
                            y = i;
                            break;
                        }
                    }
                }
                int len2 = 0;
                if (y == -1) {
                    output.print(s.substring(len));
                    output.close();
                    return;
                } else {
                    if (y == 0) {
                        if (x == 1) {
                            len2 = 2;
                            for (int j = 2; j < n - 1; j++) {
                                if (a[j] == 0) {
                                    len2++;
                                } else {
                                    break;
                                }
                            }
                        } else {
                            len2 = 1;
                            if (x == n - 1) {
                                for (int j = 1; j < n - 2; j++) {
                                    if (a[j] == 0) {
                                        len2++;
                                    } else {
                                        break;
                                    }
                                }
                            } else {
                                for (int j = 1; j < n - 1; j++) {
                                    if (a[j] == 0 || j == x) {
                                        len2++;
                                    } else {
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
                int d = len2;
                if (x >= len2) {
                    d++;
                }
                if (y >= len2) {
                    d++;
                }
                if (d >= len && len != -1) {
                    output.print(s.substring(len));
                } else {
                    for (int i = 0; i < n; i++) {
                        if (i != x && i != y && i >= len2) {
                            output.print(a[i]);
                        }
                    }
                }
            }
        } else {
            if (n == 1) {
                output.print(-1);   
            } else if (n == 2 && a[0] % 3 == 1) {
                output.print(-1);
            } else {
                int len = -1;
                for (int i = n - 1; i >= 0; i--) {
                    if (a[i] % 3 == 2) {
                        if (i != 0) {
                            for (int j = 0; j < n; j++) {
                                if (j == i) {
                                    continue;
                                }
                                output.print(a[j]);
                            }
                            output.close();
                            return;
                        } else {
                            len = 1;
                            for (int j = 1; j < n - 1; j++) {
                                if (a[j] == 0) {
                                    len++;
                                } else {
                                    break;
                                }
                            }
                            if (len == 2) {
                                output.print(s.substring(2));
                                output.close();
                                return;
                            }
                            if (len == 1) {
                                output.print(s.substring(1));
                                output.close();
                                return;
                            }
                        }
                    }
                }
                int x = -1;
                int y = -1;
                for (int i = n - 1; i >= 0; i--) {
                    if (a[i] % 3 == 1) {
                        if (x == -1) {
                            x = i;
                        } else {
                            y = i;
                            break;
                        }
                    }
                }
                int len2 = 0;
                if (y == -1) {
                    output.print(s.substring(len));
                    output.close();
                    return;
                } else {
                    if (y == 0) {
                        if (x == 1) {
                            len2 = 2;
                            for (int j = 2; j < n - 1; j++) {
                                if (a[j] == 0) {
                                    len2++;
                                } else {
                                    break;
                                }
                            }
                        } else {
                            len2 = 1;
                            if (x == n - 1) {
                                for (int j = 1; j < n - 2; j++) {
                                    if (a[j] == 0) {
                                        len2++;
                                    } else {
                                        break;
                                    }
                                }
                            } else {
                                for (int j = 1; j < n - 1; j++) {
                                    if (a[j] == 0 || j == x) {
                                        len2++;
                                    } else {
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
                int d = len2;
                if (x >= len2) {
                    d++;
                }
                if (y >= len2) {
                    d++;
                }
                if (d >= len && len != -1) {
                    output.print(s.substring(len));
                } else {
                    for (int i = 0; i < n; i++) {
                        if (i != x && i != y && i >= len2) {
                            output.print(a[i]);
                        }
                    }
                }
            }
        }
        input.close();
        output.close();
    }

    private Long nextLong() throws NumberFormatException, IOException {
        return Long.parseLong(nextString());
    }
    
    private int nextInt() throws NumberFormatException, IOException {
        return Integer.parseInt(nextString());
    }

    private String nextString() throws IOException {
        while (!stoken.hasMoreTokens()){
            String st = input.readLine();
            stoken = new StringTokenizer(st);
        }
        return stoken.nextToken();
    }
    
    
}