def main():
    order = []
    color = [0] * 26
    graph = [[] for i in range(26)]
    def dfs(v):
        color[v] = 1
        flag = True
        for u in graph[v]:
            if color[u] == 1:
                flag = False
            if color[u] == 0:
                dfs(u)
        color[v] = 2
        if flag:
            order.append(v)
    
    import sys
    n, *s = sys.stdin.read().split()
    n = int(n)
    
    for i in range(n - 1):
        if len(s[i]) > len(s[i + 1]) and s[i][:len(s[i + 1])] == s[i + 1]:
            print("Impossible")
            return
        for j in range(min(len(s[i]), len(s[i + 1]))):
            if s[i][j] != s[i + 1][j]:
                graph[ord(s[i][j]) - ord('a')].append(ord(s[i + 1][j]) - ord('a'))
                break
    
    for i in range(26):
        if color[i] == 0:
            dfs(i)
    
    if len(order) != 26:
        print("Impossible")
        return
    
    print(''.join(chr(i + ord('a')) for i in reversed(order)))
        
    
main()