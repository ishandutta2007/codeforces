def main():
    import sys
    
    tokens = [int(i) for i in sys.stdin.read().split()]
    tokens.reverse()
    
    n, m = tokens.pop(), tokens.pop()
    degree = [0] * n
    edges = [None] * m
    graph = [set() for i in range(n)]
    for i in range(m):
        a, b = tokens.pop() - 1, tokens.pop() - 1
        degree[a] += 1; degree[b] += 1
        edges[i] = (a, b)
        graph[a].add(b)
        graph[b].add(a)
    
    result = 10 ** 9
    for a, b in edges:
        if degree[a] < degree[b]: a, b = b, a
        for c in graph[a]:
            if c in graph[b]:
                result = min(result, degree[a] + degree[b] + degree[c])
    
    if result == 10 ** 9:
        print(-1)
    else:
        print(result - 6)
        
    
    
main()