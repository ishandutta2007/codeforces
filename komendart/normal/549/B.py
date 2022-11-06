def main():
    import sys
    
    tokens = sys.stdin.read().split()
    tokens.reverse()
    
    n = int(tokens.pop())
    mat = [[int(j) for j in tokens.pop()] for i in range(n)]
    prediction = [int(tokens.pop()) for i in range(n)]
    
    frequency = [0] * n
    result = []
    for step in range(n):
        for i in range(n):
            if frequency[i] == prediction[i]:
                result.append(i + 1)
                for j in range(n):
                    frequency[j] += mat[i][j]
                break
    
    print(len(result))
    print(' '.join(str(i) for i in result))
            
    
    
main()