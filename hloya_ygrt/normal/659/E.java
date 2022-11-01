import java.util.*;
import java.io.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Codeforces {
   
   static Scanner input;
   public static final int maxn = 100 * 1000 + 5;
   
   static Vector< Vector<Integer> > Graph;
   static boolean[] used;
   static boolean cycle;

   static void depthFirstSearch(int vertex, int parent)
   {
   		used[vertex] = true;
   		Iterator nextVertex = Graph.elementAt(vertex).iterator();

   		while (nextVertex.hasNext()){
   		   int to = Integer.parseInt(nextVertex.next().toString());
   			if (used[to] == true && to != parent)
   				cycle = true;
   			if (used[to] == false)
   				depthFirstSearch(to, vertex);
   		}
   }
   
   public static void main(String args[])
   {
   		input = new Scanner(System.in);
   		
   		Graph = new Vector< Vector<Integer> >();
         for (int i = 0; i < maxn; i++)
            Graph.add(new Vector<Integer> ());

   		used = new boolean[maxn];
   		Arrays.fill(used, false);

   		int numOfVertex = input.nextInt();
   		int numOfEdges = input.nextInt();

   		for (int i = 0; i < numOfEdges; i++){
   			int vertexA, vertexB;

   			vertexA = input.nextInt();
   			vertexB = input.nextInt();

   			Graph.elementAt(vertexA).add(vertexB);
   			Graph.elementAt(vertexB).add(vertexA);
   		}

   		int answer = 0;
   		for (int vertex = 1; vertex <= numOfVertex; vertex++){
   			if (used[vertex] == false){
   				cycle = false;
   				depthFirstSearch(vertex, -1);
   				if (cycle == false)
   					answer++;
   			}
   		}

   		System.out.println(answer);
   }

}