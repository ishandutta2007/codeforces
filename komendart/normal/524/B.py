

def main():
    import sys
    
    tokens = [int(i) for i in sys.stdin.read().split()]
    tokens.reverse()
    
    n = tokens.pop()
    people = [(tokens.pop(), tokens.pop()) for i in range(n)]
    
    result = float("inf")
    for i in range(n):
        for j in range(2):
            maxh = people[i][j]
            S = people[i][j ^ 1]
            for k in range(n):
                if k != i:
                    w, h = people[k]
                    w, h = min(w, h), max(w, h)
                    if w > maxh:
                        S = float("inf")
                        break
                    if h > maxh:
                        S += h
                    else:
                        S += w
            result = min(result, S * maxh)
    
    print result
                
    
    
main()