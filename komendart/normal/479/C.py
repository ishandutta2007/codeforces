def main():
    import sys
    
    tokens = [int(i) for i in sys.stdin.read().split()]
    tokens.reverse()
    
    n = tokens.pop()
    exams = [(tokens.pop(), tokens.pop()) for i in range(n)]
    exams.sort()
    
    last = -float("inf")
    for a, b in exams:
        if b >= last:
            last = b
        else:
            last = a
    
    print(last)
    
main()