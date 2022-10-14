import java.util.*;
public class D {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int[]parent=new int[n];
		HashMap<Integer,HashSet<Integer>>children=new HashMap<Integer,HashSet<Integer>>();
		children.put(0,new HashSet<Integer>());
		for(int i=1;i<n;i++){
			children.put(i,new HashSet<Integer>());
			int p=sc.nextInt()-1;
			parent[i]=p;
			children.get(p).add(i);
		}
		int[]h=new int[n];
		h[0]=1;
		for(int i=1;i<n;i++)
			h[i]=h[parent[i]]+1;
		int[]s=new int[n];
		boolean possible=true;
		for(int i=0;i<n;i++){
			s[i]=sc.nextInt();
			if((s[i]==-1)!=(h[i]%2==0))
				possible=false;
		}
		sc.close();
		long sum=s[0];
		if(possible){
			for(int i=0;i<n;i++)
				if(s[i]==-1){
					int min=Integer.MAX_VALUE;
					for(int c:children.get(i))
						min=Math.min(min,s[c]);
					if(children.get(i).isEmpty())
						min=s[parent[i]];
					if(min<s[parent[i]])
						possible=false;
					s[i]=min;
				}
			for(int i=1;i<n;i++)
				sum+=s[i]-s[parent[i]];
		}
		System.out.println(possible?sum:-1);
	}
}