def main():
    n = int(input())
    rating = [int(i) for i in input().split()]
    
    rank = []
    for i in rating:
        rank.append(1 + sum(1 if j > i else 0 for j in rating))
    
    print(' '.join(str(i) for i in rank))
    
    
main()