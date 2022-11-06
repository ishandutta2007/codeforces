def main():
    import sys
    
    tokens = [int(i) for i in sys.stdin.read().split()]
    tokens.reverse()
    
    n = tokens.pop()
    vertices = [[tokens.pop(), tokens.pop()] for i in range(n)]
    
    l = []
    for i in range(n):
        if vertices[i][0] == 1:
            l.append(i)
    
    result = []
    while l:
        v = l.pop()
        if vertices[v][0] == 0:
            continue
        u = vertices[v][1]
        result.append((v, u))
        vertices[u][0] -= 1
        vertices[u][1] ^= v
        if vertices[u][0] == 1:
            l.append(u)
    
    print(len(result))
    print('\n'.join(' '.join(str(j) for j in i) for i in result))


main()