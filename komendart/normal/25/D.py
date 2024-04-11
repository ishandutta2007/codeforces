def main():
    from random import getrandbits
    
    def find_set(v):
        if v == parent[v]: return v
        parent[v] = find_set(parent[v])
        return parent[v]
    
    def unite(a, b):
        a, b = find_set(a), find_set(b)
        if a == b: return False
        if getrandbits(1): a, b = b, a
        parent[a] = b
        return True
    
    n = int(input())
    
    parent = [i for i in range(n + 1)]
    
    spare = []
    for i in range(n - 1):
        a, b = [int(i) for i in input().split()]
        if not unite(a, b):
            spare.append((a, b))
    
    leaders = list(set(find_set(i) for i in range(1, n + 1)))
    print(len(spare))
    for i in range(len(spare)):
        print(*spare[i], end=' ')
        print(leaders[i], leaders[i + 1])
    
    
        


main()