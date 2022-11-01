import math

def main():    
    prefSum = []
    
    def GetSum( l, r ):
    	return prefSum[min( r, 199999 )] - prefSum[l - 1]
    
    # cin = open( "input.txt", 'r' )
    # n = int( cin.readline() )
    # a = list( map( int, cin.read().split() ) )
    
    # cnt = 0;
    # for i in range( 1, 200000 ):
    # 	cnt += 200000 / i
    # print( cnt )
    # exit( 0 )
    
    n = int( input() )
    a = list( map( int, input().split() ) )
    
    b = []
    for i in range( 2 * ( 10 ** 5 ) + 10 ):
    	b.append( 0 )
    for i in range( n ):
    	b[a[i]] += 1
    
    prefSum.append( 0 )
    for i in range( 1, 2 * ( 10 ** 5 ) + 10 ):
    	prefSum.append( b[i] + prefSum[i - 1] )
    
    ans = 0
    cnt = 0
    for i in range( 2 * ( 10 ** 5 ) + 10 ):
    	if b[i] == 0:
    		continue
    	l = i
    	r = 2 * i - 1
    	curAns = 0;
    	for l in range( i, 200001, i ):
    		curAns += l * ( prefSum[min( r, 200000 )] - prefSum[l - 1] )
    		r += i
    	ans = max( ans, curAns )
    print( ans )

main()