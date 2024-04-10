import java.util.Scanner;
import java.util.ArrayList;

public class Main 
{
    static Scanner scanner = new Scanner(System.in);
    public static void main(String[] args) throws Exception 
    {
        int distance[][] = bfs();
        int tc = scanner.nextInt();
        while (tc > 0)
        {
            int x = scanner.nextInt();
            int y = scanner.nextInt();
            
            System.out.println(distance[x][y]);
            tc --;
        }
    }
    static int[][] bfs() 
    {
        int maxX = 50, maxY = 50;
        int inf = 10000;
        int[][] dist = new int[maxX+1][maxY+1];
        
        for (int i=0; i<=maxX; i++)
            for (int j=0; j<=maxY; j++)
                dist[i][j] = inf;
        dist[0][0] = 0;

        ArrayList<Integer[]> bfsQueue = new ArrayList<>();
        Integer[] start = {0, 0};
        bfsQueue.add(start);

        while (!bfsQueue.isEmpty())
        {
            Integer[] currPoint = bfsQueue.get(bfsQueue.size()-1);
            bfsQueue.remove(bfsQueue.size()-1);

            for (int i=0; i<=maxX; i++)
            {
                for (int j=0; j<=maxY; j++)
                {
                    int distX = currPoint[0] - i;
                    int distY = currPoint[1] - j;
                    int sqroot = (int)Math.round(Math.sqrt(distX*distX + distY*distY));
                    if (sqroot * sqroot == distX*distX + distY*distY)
                    {
                        if (dist[i][j] > dist[currPoint[0]][currPoint[1]] + 1)
                        {
                            dist[i][j] = dist[currPoint[0]][currPoint[1]] + 1;
                            Integer[] thisPoint = {i, j};
                            bfsQueue.add(thisPoint);
                        }
                    }
                }
            }
        }

        return dist;
    }
}