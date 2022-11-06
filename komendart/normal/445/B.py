def main():
    def dfs(v):
        used[v] = 1
        for i in graph[v]:
            if not used[i]:
                dfs(i)
    
    n, m = [int(i) for i in input().split()]
    graph = [[] for i in range(n)]
    
    for i in range(m):
        x, y = [int(i) for i in input().split()]
        graph[x - 1].append(y - 1)
        graph[y - 1].append(x - 1)
    
    used = [0 for i in range(n)]
    
    components = 0
    for i in range(n):
        if not used[i]:
            components += 1
            dfs(i)
    
    print(2 ** (n - components))

main()