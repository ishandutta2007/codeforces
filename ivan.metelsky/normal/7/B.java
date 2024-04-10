import java.util.*;

public class Solution {
    class Block implements Comparable<Block> {
        int start;
        int len;
        int ID;
        public int compareTo(Block other) {
            return this.start - other.start;
        }
    }
    
    void doMain() {
        Scanner sc = new Scanner(System.in);
        int opCnt = sc.nextInt();
        int memSize = sc.nextInt();
        
        List<Block> blocks = new ArrayList<Block>();
        boolean[] memory = new boolean[memSize];
        int cnt = 0;
        
        for (int i=0; i<opCnt; i++) {
            String s = sc.next();
            if (s.equals("alloc")) {
                int len = sc.nextInt();
                boolean can = false;
                for (int a=0; a + len <= memSize; a++) {
                    can = true;
                    for (int b=a; b < a + len; b++)
                        if (memory[b]) {
                            can = false;
                            break;
                        }
                    if (can) {
                        for (int b=a; b < a + len; b++) memory[b] = true;
                        Block bb = new Block();
                        bb.ID = ++cnt;
                        bb.start = a;
                        bb.len = len;
                        blocks.add(bb);
                        System.out.println(cnt);
                        break;
                    }
                }
                if (!can) System.out.println("NULL");
            }
            if (s.equals("erase")) {
                int ID = sc.nextInt();
                boolean find = false;
                for (int a=0; a < blocks.size(); a++)
                    if (blocks.get(a).ID == ID) {
                        for (int b=blocks.get(a).start; b < blocks.get(a).start + blocks.get(a).len; b++)
                            memory[b] = false;
                        blocks.remove(a);
                        find = true;
                        break;
                    }
                if (!find) System.out.println("ILLEGAL_ERASE_ARGUMENT");
            }
            if (s.equals("defragment")) {
                Collections.sort(blocks);
                Arrays.fill(memory, false);
                int cur = 0;
                for (int a=0; a < blocks.size(); a++) {
                    blocks.get(a).start = cur;
                    for (int b=cur; b < cur + blocks.get(a).len; b++)
                        memory[b] = true;
                    cur += blocks.get(a).len;
                }
            }
        }
        
        sc.close();
    }
    
    public static void main(String[] args) throws Exception {
        (new Solution()).doMain();
    }
}