def main():
    from collections import deque
    
    n, m = [int(i) for i in input().split()]
    children = deque([0, int(v), i + 1] for i, v in enumerate(input().split()))
    
    while len(children) > 1:
        tmp = children.popleft()
        tmp[0] += m
        if tmp[1] > tmp[0]:
            children.append(tmp)
    
    print(children.popleft()[2])


main()